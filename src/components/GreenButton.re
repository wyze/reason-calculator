let component = ReasonReact.statelessComponent("GreenButton");

let getClassName = className =>
  Styles.merge([
    Styles.make(~background="#3bf3a9", ()) |> Styles.className,
    Styles.make(~color="#3bf3a9", ()) |> Styles.hover,
    Util.strEmpty(className) ? Styles.empty : className,
  ]);

let make = (~action, ~className="", ~dispatch, _children) => {
  ...component,
  render: _self =>
    <OperationButton className=getClassName(className) dispatch action />
};
