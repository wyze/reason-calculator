open Jest;
open Expect;

let _ =

describe "ValueButton" (fun _ => {
  test "renders" (fun _ => {
    let dispatch = fun _ => ();
    let value = "1";
    let tree = ValueButton.createElement ::dispatch ::value children::[] ()
      |> Renderer.render;

    expect tree |> toMatchSnapshot;
  });

  test "renders expanded button" (fun _ => {
    let dispatch = fun _ => ();
    let expand = true;
    let value = "1";
    let tree = ValueButton.createElement ::dispatch ::expand ::value children::[] ()
      |> Renderer.render;

    expect tree |> toMatchSnapshot;
  });
});
