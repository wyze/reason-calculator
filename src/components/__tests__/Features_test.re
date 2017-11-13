open Jest;
open Expect;

let _ =

describe("Features", () => {
  test("renders", () => {
    let tree = <Features /> |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
