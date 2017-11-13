const HtmlPlugin = require('webpack-html-plugin')
const join = require('path').join

const stats = 'errors-only'

module.exports = [
  {
    entry: './lib/js/src',
    output: {
      filename: 'bundle.js',
      path: join(__dirname, 'dist'),
      publicPath: '/',
    },
    plugins: [
      new HtmlPlugin({
        template: './index.html',
      }),
    ],
    stats,
    devServer: {
      stats,
    },
  },
]
