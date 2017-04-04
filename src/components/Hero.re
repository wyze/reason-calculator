module Hero = {
  include ReactRe.Component;
  let name = "Hero";

  type props = ();

  let className: string =
    Styles.merge [
      Styles.make
        background::"#dedede"
        borderRadius::"5px"
        display::"block"
        padding::"1em"
        marginBottom::"4em"
        textAlign::"center"
        width::"30em"
        ()
      |> Styles.className,
      Styles.make width::"35em" () |> Styles.small,
    ];


  let render _ =>
    <div className>
      <Title />
      <Features />
    </div>;
};

include ReactRe.CreateComponent Hero;

let createElement = wrapProps ();
