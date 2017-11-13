let component = ReasonReact.statelessComponent("ButtonGroup");

let className: string =
  Styles.make(~display="flex", ()) |> Styles.className;

let make = children => {
  ...component,
  render: _self =>
    ReasonReact.createDomElement("div", ~props={"className": className}, children)
};
