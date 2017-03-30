module ClearButton = {
  include ReactRe.Component;
  let name = "ClearButton";

  type props = {
    dispatch: Store.action => unit,
  };

  let className: string =
    Styles.make
      background::"#3bf3a9"
      flex::"75%"
      ()
    |> Styles.className;

  let render { props: { dispatch } } =>
    <OperationButton className dispatch action=Clear />;
};

include ReactRe.CreateComponent ClearButton;

let createElement ::dispatch => wrapProps { dispatch: dispatch };
