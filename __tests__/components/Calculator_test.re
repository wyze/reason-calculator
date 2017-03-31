open Jest;
open Expect;

let _ =

describe "Calculator" (fun _ => {
  test "renders" (fun _ => {
    let children = [ <div>(ReactRe.stringToElement "child")</div>, <span /> ];
    let tree = Calculator.createElement ::children () |> Renderer.render;

    (expect tree) |> toMatchSnapshot;
  });
});
