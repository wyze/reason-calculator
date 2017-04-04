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

### [v1.1.0](https://github.com/wyze/reason-calculator/releases/tag/v1.1.0) (2017-04-04)

* [[`872823b937`](https://github.com/wyze/reason-calculator/commit/872823b937)] - Cleanup PosNeg handling and fix potential bug when total would be 0 (Neil Kistner)
* [[`7ce73e39fe`](https://github.com/wyze/reason-calculator/commit/7ce73e39fe)] - Add positive/negative button (Neil Kistner)
* [[`164e1d9cf1`](https://github.com/wyze/reason-calculator/commit/164e1d9cf1)] - Remove all the reversing of the operations (Neil Kistner)

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
