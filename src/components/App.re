module Styles = {
  open Css;

  let buttons =
    style([
      display(`flex),
      selector(
        "&:last-of-type",
        [
          selector(
            "& :first-of-type",
            [
              flexBasis(pct(50.)),
              paddingLeft(em(0.9)),
              textAlign(`left),
            ],
          ),
        ],
      ),
    ]);

  let calculator =
    style([
      background(hex("838383")),
      borderRadius(px(5)),
      overflow(hidden),
      width(em(14.)),
    ]);

  let container =
    style([alignItems(`center), display(`flex), flexDirection(`column)]);

  let display =
    style([
      alignItems(center),
      color(hex("fafafa")),
      display(`flex),
      fontSize(em(1.5)),
      height(em(2.5)),
      justifyContent(flexEnd),
      padding2(~v=zero, ~h=em(1.)),
    ]);
};

[@react.component]
let make = () => {
  let display = Store.useDisplay();

  <div className=Styles.container>
    <Hero />
    <div className=Styles.calculator>
      <label className=Styles.display>
        display->React.string
        <input type_="hidden" />
      </label>
      <div className=Styles.buttons>
        <Button action=Clear text="C" />
        <Button action=PosNeg text={js|+/\u2212|js} />
        <Button action=Percent text="%" />
        <Button action=Divide text={js|\u00f7|js} />
      </div>
      <div className=Styles.buttons>
        <Button action="7"->Input text="7" />
        <Button action="8"->Input text="8" />
        <Button action="9"->Input text="9" />
        <Button action=Multiply text={js|\u00d7|js} />
      </div>
      <div className=Styles.buttons>
        <Button action="4"->Input text="4" />
        <Button action="5"->Input text="5" />
        <Button action="6"->Input text="6" />
        <Button action=Subtract text={js|\u2212|js} />
      </div>
      <div className=Styles.buttons>
        <Button action="1"->Input text="1" />
        <Button action="2"->Input text="2" />
        <Button action="3"->Input text="3" />
        <Button action=Add text="+" />
      </div>
      <div className=Styles.buttons>
        <Button action="0"->Input text="0" />
        <Button action="."->Input text="." />
        <Button action=Equals text="=" />
      </div>
    </div>
  </div>;
};
