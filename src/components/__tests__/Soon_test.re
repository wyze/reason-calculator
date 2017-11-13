open Jest;
open Expect;

let _ =

describe("Soon", () => {
  test("renders", () => {
    let tree = <Soon /> |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
