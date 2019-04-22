module Styles = {
  open Css;

  let container =
    merge([
      style([
        background(hex("dedede")),
        borderRadius(px(5)),
        display(block),
        padding(em(1.)),
        marginBottom(em(4.)),
        textAlign(center),
        width(em(30.)),
      ]),
      style([media("(min-width: 53.125em)", [width(em(35.))])]),
    ]);

  let title = style([fontSize(em(1.5))]);
};

[@react.component]
let make = () =>
  <div className=Styles.container>
    <h1 className=Styles.title> "Reason Calculator"->React.string </h1>
    <Features />
  </div>;
