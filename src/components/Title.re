let component = ReasonReact.statelessComponent("Title");

let className: string =
  Styles.make(~fontSize="1.5em", ()) |> Styles.className;

let make = _children => {
  ...component,
  render: _self =>
    <h1 className>
      {ReasonReact.stringToElement("Reason Calculator")}
    </h1>
};
