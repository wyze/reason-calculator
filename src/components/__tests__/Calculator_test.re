open Jest;
open Expect;

let _ =

describe("Calculator", () => {
  test("renders", () => {
    let tree = (
      <Calculator>
        <div>{ReasonReact.stringToElement("child")}</div>
        <span />
      </Calculator>
    ) |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
