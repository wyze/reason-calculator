open Jest;
open Expect;

let _ =

describe "Features" (fun _ => {
  test "renders" (fun _ => {
    let tree = Features.createElement children::[] () |> ReactShallowRenderer.renderWithRenderer;

    expect tree |> toMatchSnapshot;
  });
});
