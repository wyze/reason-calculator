module GreenButton = {
  include ReactRe.Component;
  let name = "GreenButton";

  type props = {
    action: Store.action,
    className: string,
    dispatch: Store.action => unit,
  };

  let getClassName className =>
    Styles.merge [
      Styles.make background::"#3bf3a9" () |> Styles.className,
      Styles.make color::"#3bf3a9" () |> Styles.hover,
      Util.strEmpty className ? Styles.empty : className,
    ];

  let render { props: { action, className, dispatch } } =>
    <OperationButton className=(getClassName className) dispatch action />;
};

include ReactRe.CreateComponent GreenButton;

let createElement ::action ::className="" ::dispatch =>
  wrapProps { action, className, dispatch };
