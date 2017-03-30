module ButtonGroup = {
  include ReactRe.Component;
  let name = "ButtonGroup";

  type props = {
    children: list ReactRe.reactElement,
  };

  let className: string =
    Styles.make display::"flex" () |> Styles.className;

  let render { props: { children } } =>
    <div className>
      (ReactRe.listToElement children)
    </div>;
};

include ReactRe.CreateComponent ButtonGroup;

let createElement ::children =>
  wrapProps { children: children } ::children;
