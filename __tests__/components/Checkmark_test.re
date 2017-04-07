open Jest;
open Expect;

let _ =

describe "Checkmark" (fun _ => {
  test "renders" (fun _ => {
    let tree = Checkmark.createElement children::[] () |> Renderer.render;

    expect tree |> toMatchSnapshot;
  });
});
