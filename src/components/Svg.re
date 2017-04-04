module Svg = {
  include ReactRe.Component;
  let name = "Svg";

  type props = {
    children: list ReactRe.reactElement,
  };

  let viewBox: string = "0 0 64 64";
  let className: string =
    Styles.merge [
      Styles.make
        height::"16px"
        marginRight::"1em"
        marginTop::"0"
        width::"16px"
        ()
      |> Styles.className,
      Styles.make marginTop::"-6px" () |> Styles.small,
    ];

  let render { props: { children } } =>
    <div className>
      <svg xmlns="http://www.w3.org/2000/svg" viewBox enableBackground=("new " ^ viewBox)>
        (ReactRe.listToElement children)
      </svg>
    </div>;
};

include ReactRe.CreateComponent Svg;

let createElement ::children => wrapProps { children: children } ::children;
