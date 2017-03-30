module Display = {
  include ReactRe.Component;
  let name = "Display";

  type props = {
    output: string,
  };

  let className: string =
    Styles.make
      alignItems::"center"
      color::"#fafafa"
      display::"flex"
      fontSize::"1.5em"
      height::"2.5em"
      justifyContent::"flex-end"
      padding::"0 1em"
      ()
    |> Styles.className;

  let render { props: { output } } =>
    <div className>
      (ReactRe.stringToElement output)
    </div>;
};

include ReactRe.CreateComponent Display;

let createElement ::output => wrapProps { output: output };
