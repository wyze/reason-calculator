module App = {
  include ReactRe.Component;
  let name = "App";

  type props = {
    dispatch: Store.action => unit,
    state: Store.state,
  };

  let className: string =
    Styles.make
      alignItems::"center"
      display::"flex"
      flexDirection::"column"
      ()
    |> Styles.className;

  let render { props: { dispatch, state: { operations } } } => {
    let output = Operation.getInput operations;

    <main className>
      <Hero />
      <Calculator>
        <Display output />
        <Buttons dispatch />
      </Calculator>
    </main>;
  };
};

include ReactRe.CreateComponent App;

let createElement ::state ::dispatch => wrapProps { dispatch, state };
