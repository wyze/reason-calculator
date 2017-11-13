open Jest;
open Expect;

let _ =

describe("Checkmark", () => {
  test("renders", () => {
    let tree = <Checkmark /> |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
