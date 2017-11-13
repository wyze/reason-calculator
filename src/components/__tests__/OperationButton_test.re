open Jest;
open Expect;

let _ =

describe("OperationButton", () => {
  let action = Action.Add;
  let dispatch = _action => ();

  test("renders", () => {
    let tree = <OperationButton action dispatch />
      |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });

  test("renders a class name", () => {
    let className = Styles.make(~color="rebeccapurple", ()) |> Styles.className;
    let tree = <OperationButton action className dispatch />
      |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
