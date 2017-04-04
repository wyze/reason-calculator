module ClearButton = {
  include ReactRe.Component;
  let name = "ClearButton";

  type props = {
    dispatch: Store.action => unit,
  };

  let className: string =
    Styles.make flex::"50%" () |> Styles.className;

  let render { props: { dispatch } } =>
    <GreenButton className dispatch action=Clear />;
};

include ReactRe.CreateComponent ClearButton;

let createElement ::dispatch => wrapProps { dispatch: dispatch };
