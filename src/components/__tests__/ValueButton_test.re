open Jest;
open Expect;

let _ =

describe("ValueButton", () => {
  let dispatch = _action => ();
  let value = "1";

  test("renders", () => {
    let tree = <ValueButton dispatch value />
      |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });

  test("renders expanded button", () => {
    let tree = <ValueButton dispatch expand=true value />
      |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
