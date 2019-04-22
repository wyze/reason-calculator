type emoji =
  | Checkmark
  | Soon;

module Styles = {
  open Css;

  let container =
    merge([
      style([
        alignItems(`center),
        display(`flex),
        flexBasis(pct(40.)),
        height(em(2.)),
      ]),
      style([media("(min-width: 53.125em)", [flexBasis(pct(35.))])]),
    ]);
};

[@react.component]
let make = (~emoji: emoji, ~text) =>
  <div className=Styles.container>
    {
      switch (emoji) {
      | Checkmark => <Checkmark />
      | Soon => <Soon />
      }
    }
    <h3> text->React.string </h3>
  </div>;
