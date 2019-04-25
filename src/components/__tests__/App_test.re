open Jest;
open Expect;
open JestDom;
open ReactTestingLibrary;
open Webapi.Dom;

let unwrap = element =>
  switch (element) {
  | Some(el) => el
  | None => raise(Failure("Element not found"))
  };

test("renders the title", () =>
  <Root />
  |> render
  |> getByText(~matcher=`Str("Reason Calculator"))
  |> expect
  |> toBeInTheDocument
);

testAll(
  "renders feature",
  [
    ("Simple operations", "checkmark"),
    ("Decimals", "checkmark"),
    ("Percentage", "checkmark"),
    ("Positive/Negative", "checkmark"),
    ("Advanced options", "soon"),
    ("Operation history", "soon"),
  ],
  ((feature, icon)) =>
  <Root />
  |> render
  |> getByText(
       ~matcher=
         `Func(
           (_, el) =>
             el->Element.parentNode->unwrap->Node.textContent == icon
             ++ feature,
         ),
     )
  |> expect
  |> toBeInTheDocument
);

test("renders display", () => {
  let app = <Root /> |> render;
  let oneButton = app |> getByText(~matcher=`Str("1"));

  oneButton->FireEvent.click;
  oneButton->FireEvent.click;

  app |> getByLabelText(~matcher=`Str("11")) |> expect |> toBeInTheDocument;
});

testAll(
  "performs operation",
  [
    (["1", "+", "2", "="], "3"),
    (["1", {js|\u2212|js}, "2", "="], "-1"),
    (["2", {js|\u00d7|js}, "3", "="], "6"),
    (["4", {js|\u00f7|js}, "2", "="], "2"),
  ],
  ((operations, result)) => {
    let app = <Root /> |> render;

    List.iter(
      operation =>
        app |> getByText(~matcher=`Str(operation)) |> FireEvent.click,
      operations,
    );

    app
    |> getByLabelText(~matcher=`Str(result))
    |> expect
    |> toBeInTheDocument;
  },
);
