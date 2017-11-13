let component = ReasonReact.statelessComponent("OperationButton");

let button = className =>
  Styles.merge([
    Styles.button,
    Util.strEmpty(className)
      ? Styles.merge([
          Styles.make(~background="#ff8754", ()) |> Styles.className,
          Styles.make(~color="#ff8754", ()) |> Styles.hover,
        ])
      : className,
  ]);

let handleClick = (dispatch, action) => _event => dispatch(action);

let make = (~action, ~className="", ~dispatch, _children) => {
  ...component,
  render: _self =>
    <button
      className=button(className)
      dangerouslySetInnerHTML={"__html": Action.toText(action)}
      onClick=handleClick(dispatch, action)
    />
};
