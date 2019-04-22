module Styles = {
  open Css;

  let container =
    merge([
      style([
        height(px(16)),
        marginRight(em(1.)),
        marginTop(`zero),
        width(px(16)),
      ]),
      style([media("(min-width: 53.125em)", [marginTop(px(-6))])]),
    ]);
};

[@react.component]
let make = (~children) =>
  <div className=Styles.container>
    <svg
      xmlns="http://www.w3.org/2000/svg"
      viewBox="0 0 64 64">
      <g> children </g>
    </svg>
  </div>;
