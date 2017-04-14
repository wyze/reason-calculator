open Jest;
open Expect;

let _ =

describe "Feature" (fun _ => {
  test "renders checkmark emoji" (fun _ => {
    let emoji = Feature.Feature.Checkmark;
    let text = "A feature";
    let tree = Feature.createElement ::emoji ::text children::[] ()
      |> ReactShallowRenderer.renderWithRenderer;

    expect tree |> toMatchSnapshot
  });

  test "renders soon emoji" (fun _ => {
    let emoji = Feature.Feature.Soon;
    let text = "A feature";
    let tree = Feature.createElement ::emoji ::text children::[] ()
      |> ReactShallowRenderer.renderWithRenderer;

    expect tree |> toMatchSnapshot;
  });
});
