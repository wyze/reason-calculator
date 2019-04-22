module Styles = {
  open Css;

  let container =
    style([display(`flex), flexWrap(`wrap), justifyContent(`spaceAround)]);
};

[@react.component]
let make = () =>
  <div className=Styles.container>
    <Feature emoji=Checkmark text="Simple operations" />
    <Feature emoji=Checkmark text="Decimals" />
    <Feature emoji=Checkmark text="Percentage" />
    <Feature emoji=Checkmark text="Positive/Negative" />
    <Feature emoji=Soon text="Advanced options" />
    <Feature emoji=Soon text="Operation history" />
  </div>;
