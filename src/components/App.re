let component = ReasonReact.statelessComponent("App");

let className: string =
  Styles.make(
    ~alignItems="center",
    ~display="flex",
    ~flexDirection="column",
    ()
  ) |> Styles.className;

let make = (~state as { Store.operations }, ~dispatch, _children) => {
  let output = Operation.getInput(operations);

  {
    ...component,
    render: _self =>
      <main className>
        <Hero />
        <Calculator>
          <Display output />
          <Buttons dispatch />
        </Calculator>
      </main>
  };
};
