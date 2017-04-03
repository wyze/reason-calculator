module ClearButton = {
  include ReactRe.Component;
  let name = "ClearButton";

  type props = {
    dispatch: Store.action => unit,
  };

  let className: string =
    Styles.merge [
      Styles.make background::"#3bf3a9" flex::"75%" () |> Styles.className,
      Styles.make color::"#3bf3a9" () |> Styles.hover,
    ];

  let render { props: { dispatch } } =>
    <OperationButton className dispatch action=Clear />;
};

include ReactRe.CreateComponent ClearButton;

let createElement ::dispatch => wrapProps { dispatch: dispatch };
