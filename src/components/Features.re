let component = ReasonReact.statelessComponent("Features");

let className: string =
  Styles.make(
    ~display="flex",
    ~flexWrap="wrap",
    ~justifyContent="space-around",
    ()
  ) |> Styles.className;

let make = _children => {
  ...component,
  render: _self =>
    <div className>
      <Feature emoji=Checkmark text="Simple operations" />
      <Feature emoji=Checkmark text="Decimals" />
      <Feature emoji=Checkmark text="Percentage" />
      <Feature emoji=Checkmark text="Positive/Negative" />
      <Feature emoji=Soon text="Advanced options" />
      <Feature emoji=Soon text="Operation history" />
    </div>
};
