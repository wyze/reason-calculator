let component = ReasonReact.statelessComponent("Calculator");

let className: string =
  Styles.make(
    ~background="#838383",
    ~borderRadius="5px",
    ~overflow="hidden",
    ~width="14em",
    ()
  ) |> Styles.className;

let make = children => {
  ...component,
  render: _self =>
    ReasonReact.createDomElement("div", ~props={"className": className}, children)
};
