open Jest;
open Expect;

let _ =

describe "Hero" (fun _ => {
  test "renders" (fun _ => {
    let tree = Hero.createElement children::[] () |> Renderer.render;

    (expect tree) |> toMatchSnapshot;
  });
});
