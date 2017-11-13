open Jest;
open Expect;

let _ =

describe("ButtonGroup", () => {
  test("renders", () => {
    let tree = (
      <ButtonGroup>
        <div>{ReasonReact.stringToElement("child")}</div>
        <span />
      </ButtonGroup>
    ) |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
