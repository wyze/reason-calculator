module OperationButton = {
  include ReactRe.Component;
  let name = "OperationButton";

  type props = {
    action: Store.action,
    className: string,
    dispatch: Store.action => unit,
  };

  let operator: string =
    Styles.make background::"#ff8754" () |> Styles.className;
  let button className =>
    Styles.merge [
      Styles.button,
      operator,
      Util.strEmpty className ? Styles.empty : className,
    ];

  let handleClick dispatch action => fun _ => dispatch action;

  let render { props: { action, className, dispatch } } =>
    <button
      className=(button className)
      dangerouslySetInnerHTML=((Obj.magic { "__html": Action.toText action }): string)
      onClick=(handleClick dispatch action)
    />;
};

include ReactRe.CreateComponent OperationButton;

let createElement ::action ::className="" ::dispatch =>
  wrapProps { action, className, dispatch };
