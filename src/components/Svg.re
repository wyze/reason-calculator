module Styles = {
  open Css;

  let container =
    style([
      height(px(16)),
      marginRight(em(1.)),
      marginTop(`zero),
      width(px(16)),
    ]);
};

[@react.component]
let make = (~children, ~title) =>
  <svg
    className=Styles.container
    viewBox="0 0 64 64"
    xmlns="http://www.w3.org/2000/svg">
    <title> title->React.string </title>
    <g> children </g>
  </svg>;
