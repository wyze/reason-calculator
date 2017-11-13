let component = ReasonReact.statelessComponent("ValueButton");

let button = expand =>
  Styles.merge([
    Styles.button,
    expand
      ? Styles.make(~flex="50%", ~paddingLeft=".9em", ~textAlign="left", ()) |> Styles.className
      : Styles.empty
  ]);

let handleClick = (dispatch, value) => _event =>
  Action.Input(value) |> dispatch;

let make = (~dispatch, ~expand=false, ~value, _children) => {
  ...component,
  render: _self =>
    <button className=button(expand) onClick=handleClick(dispatch, value) value>
      {ReasonReact.stringToElement(value)}
    </button>
};
