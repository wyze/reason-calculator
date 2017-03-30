const execa = require('execa')
const readFile = require('fs').readFileSync
const readPkg = require('read-pkg')
const writeFile = require('fs').writeFileSync

// get version from pkg.json
const getVersionAndUrl =
  ({ repository: { url }, version }) => ({ url, version })

// npm run changelog (and grab output)
const getChanges = ({ url, version }) => {
  const { stdout } = execa.sync('npm', [ 'run', 'changelog', '--silent' ])
  const changes = stdout.trim().split(' \n')

  return { changes, url, version }
}

// modify changelog.md
const updateChangelog = ({ changes, url, version }) => {
  const file = 'changelog.md'
  const changelog = readFile(file).toString().split('\n')
  const date = new Date().toJSON().split('T').shift()
  const tag = `v${version}`
  const repo = url.replace(/\.?git(?!hub)\+?/g, '')
  const header = `### [${tag}](${repo}/releases/tag/${tag}) (${date})`
  const formatted = [ header, '', ...changes ]

  writeFile(
    file,
    [
      ...changelog.slice(0, 2),
      ...formatted,
      ...changelog.slice(1),
    ].join('\n')
  )

  return formatted
}

// modify readme.md
const updateReadme = formatted => {
  const file = 'readme.md'
  const readme = readFile(file).toString().split('\n')
  const start = '> [Full Change Log](changelog.md)'
  const end = '## License'

  writeFile(
    file,
    [
      ...readme.slice(0, readme.indexOf(start) + 2),
      ...formatted,
      ...readme.slice(readme.indexOf(end) - 1),
    ].join('\n')
  )
}

// git add
const runGitAdd = () => {
  execa.sync('git', [ 'add', '--all' ])
}

readPkg()
  .then(getVersionAndUrl)
  .then(getChanges)
  .then(updateChangelog)
  .then(updateReadme)
  .then(runGitAdd)
