let component = ReasonReact.statelessComponent("Display");

let className: string =
  Styles.make(
    ~alignItems="center",
    ~color="#fafafa",
    ~display="flex",
    ~fontSize="1.5em",
    ~height="2.5em",
    ~justifyContent="flex-end",
    ~padding="0 1em",
    ()
  ) |> Styles.className;

let make = (~output, _children) => {
  ...component,
  render: _self =>
    <div className>
      {ReasonReact.stringToElement(output)}
    </div>
};
