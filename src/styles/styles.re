/* import glamor */
external glamor : 'glamor = "glamor" [@@bs.module];

type style2;

let make = ReactDOMRe.Style.make;

/* Glamor helpers */
let global tag styles => glamor##css##global tag styles;
let insert styles => glamor##css##insert styles;
let className styles => glamor##css styles;

/* Empty */
let empty: string = className (make ());

/* 'a -> bool */
let removeEmpty style => style != empty;

/* option string -> list 'a -> string */
let merge ::separator=" " lstStyles =>
  lstStyles
    |> List.filter removeEmpty
    |> Array.of_list
    |> Array.map Js.String.make
    |> Js.Array.joinWith separator;

/* Color palette: http://paletton.com/#uid=6340W0klr++cu++he++ogWkkcvx */

/* TODO: Make PR to reason-react to add these */
external make2 :
  _MozOsxFontSmoothing::string? =>
  _WebkitFontSmoothing::string? =>
  _WebkitOverflowScrolling::string? =>
  textRendering::string? =>
  overflowX::string? =>
  overflowY::string? =>
  unit =>
  style2 = "" [@@bs.obj];

let fontFamily: string =
  merge separator::", "
    [
      "-apple-system",
      "BlinkMacSystemFont",
      "'Segoe UI'",
      "Roboto",
      "Helvetica",
      "Arial",
      "sans-serif",
      "'Apple Color Emoji'",
      "'Segoe UI Emoji'",
      "'Segoe UI Symbol'"
    ];

/* Resets: based off https://bulma.io */
let resets = [
  /* Blocks */
  ( "html,body,h1,h2,h3", make margin::"0" padding::"0" () ),

  /* Headings */
  ( "h1,h2,h3", make fontSize::"100%" fontWeight::"normal" () ),

  /* Form */
  ( "button", make margin::"0" () ),

  /* Box sizing */
  ( "html", make boxSizing::"inherit" () ),
  ( "*,*:after,*:before", make boxSizing::"border-box" () ),
];

/* Global styles */
let styles = [
  ( ":root", make fontSize::".75em" () ),
  ( "html", make lineHeight::"1.45" () ),
  (
    "body",
    make
      alignItems::"center"
      background::"#efefef"
      color::"#838383"
      display::"flex"
      fontFamily::fontFamily
      height::"100vh"
      justifyContent::"center"
      ()
  ),
];

/* Global styles2 */
let styles2 = [
  (
    "html",
    make2
      _MozOsxFontSmoothing::"grayscale"
      _WebkitFontSmoothing::"antialiased"
      _WebkitOverflowScrolling:: "touch"
      overflowX::"hidden"
      textRendering::"optimizeLegibility"
      ()
  ),
];

/* Media queries */
let medias = [
  "@media only screen and (min-width: 25em) and (max-width: 93.75em) {
    :root {
      font-size: calc(.75em + (18 - 12) * ((100vw - 25em) / (1500 - 400)))
    }
  }",
  "@media only screen and (min-width: 93.75em) {
    :root { font-size: 1.125em }
  }",
];

/* Style helper */
let style ( tag, styles ) => glamor##css##global tag styles;
let media mq => glamor##css##insert mq;

/* Apply global styles/styles2 & media queries */
let () = List.iter style (resets @ styles);
let () = List.iter style styles2;
let () = List.iter media medias;

/* Button */
let button: string =
  className (
    make
      background::"#6d71ff"
      border::"none"
      color::"#fafafa"
      cursor::"pointer"
      display::"inline-block"
      flex::"25%"
      fontSize::"1.5em"
      lineHeight::"2"
      outline::"none"
      ()
  );
