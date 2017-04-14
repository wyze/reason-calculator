module OperationButton = {
  include ReactRe.Component;
  let name = "OperationButton";

  type props = {
    action: Store.action,
    className: string,
    dispatch: Store.action => unit,
  };

  let button className =>
    Styles.merge [
      Styles.button,
      Util.strEmpty className
        ? Styles.merge [
            Styles.make background::"#ff8754" () |> Styles.className,
            Styles.make color::"#ff8754" () |> Styles.hover,
          ]
        : className,
    ];

  let handleClick dispatch action => fun _ => dispatch action;

  let render { props: { action, className, dispatch } } =>
    <button
      className=(button className)
      dangerouslySetInnerHTML={ "__html": Action.toText action }
      onClick=(handleClick dispatch action)
    />;
};

include ReactRe.CreateComponent OperationButton;

let createElement ::action ::className="" ::dispatch =>
  wrapProps { action, className, dispatch };
