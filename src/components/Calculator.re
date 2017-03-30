module Calculator = {
  include ReactRe.Component;
  let name = "Calculator";

  type props = {
    children: list ReactRe.reactElement,
  };

  let className: string =
    Styles.make
      background::"#838383"
      borderRadius::"5px"
      overflow::"hidden"
      width::"14em"
      ()
    |> Styles.className;

  let render { props: { children } } =>
    <div className>
      (ReactRe.listToElement children)
    </div>;
};

include ReactRe.CreateComponent Calculator;

let createElement ::children => wrapProps { children: children } ::children;
