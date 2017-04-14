open Jest;
open Expect;

let _ =

describe "Checkmark" (fun _ => {
  test "renders" (fun _ => {
    let tree = Checkmark.createElement children::[] ()
      |> ReactShallowRenderer.renderWithRenderer;

    expect tree |> toMatchSnapshot;
  });
});
