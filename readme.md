# reason-calculator

[![Website][website-image]][website-url]
[![Build Status][travis-image]][travis-url]
[![dependencies][deps-image]][deps-url]
[![devDependencies][depsdev-image]][depsdev-url]

> A calculator built with [Reason](https://github.com/facebook/reason) and [reason-react](https://github.com/reasonml/reason-react).

## Live Demo

https://reason-calculator.surge.sh

## Setup

```sh
$ git clone https://github.com/wyze/reason-calculator.git
$ cd reason-calculator
$ yarn # or `npm install`
```

## Development

```sh
$ npm run dev
```

## Build

```sh
$ npm run build
```

## Change Log

> [Full Change Log](changelog.md)

### [v1.0.1](https://github.com/wyze/reason-calculator/releases/tag/v1.0.1) (2017-04-03)

* [[`7db4e02f0f`](https://github.com/wyze/reason-calculator/commit/7db4e02f0f)] - Fix bug when changing operation (i.e. Add -\> Subtract) (Neil Kistner)
* [[`30d699670c`](https://github.com/wyze/reason-calculator/commit/30d699670c)] - Quick style update (Neil Kistner)
* [[`eea0ba9618`](https://github.com/wyze/reason-calculator/commit/eea0ba9618)] - Fix bug with Input action after Equals action (Neil Kistner)
* [[`d08ec46285`](https://github.com/wyze/reason-calculator/commit/d08ec46285)] - General project cleanup (Neil Kistner)
* [[`d79a2512c6`](https://github.com/wyze/reason-calculator/commit/d79a2512c6)] - Add tests with `bs-jest` (Neil Kistner)
* [[`1b1634d0f6`](https://github.com/wyze/reason-calculator/commit/1b1634d0f6)] - Add Svg component (Neil Kistner)

## License

MIT © [Neil Kistner](https://neilkistner.com)

[website-image]: https://img.shields.io/website-up-down-green-red/https/reason-calculator.surge.sh.svg?style=flat-square
[website-url]: https://reason-calculator.surge.sh

[travis-image]: https://img.shields.io/travis/wyze/reason-calculator.svg?style=flat-square
[travis-url]: https://travis-ci.org/wyze/reason-calculator


[deps-image]: https://img.shields.io/david/wyze/reason-calculator.svg?style=flat-square
[deps-url]: https://david-dm.org/wyze/reason-calculator

[depsdev-image]: https://img.shields.io/david/dev/wyze/reason-calculator.svg?style=flat-square
[depsdev-url]: https://david-dm.org/wyze/reason-calculator?type=dev
