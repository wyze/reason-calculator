open Jest;
open Expect;

let _ =

describe "App" (fun _ => {
  test "renders" (fun _ => {
    let dispatch = fun _ => ();
    let state = Store.init;
    let tree = App.createElement ::state ::dispatch children::[] ()
      |> ReactShallowRenderer.renderWithRenderer;

    expect tree |> toMatchSnapshot;
  });
});
