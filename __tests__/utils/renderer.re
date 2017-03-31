type t;

/* TODO: Make external module */

external createRenderer : unit => t = "" [@@bs.val] [@@bs.module "react-addons-test-utils"];
external render : t => ReactRe.reactElement => unit = "" [@@bs.send];
external getRenderOutput : t => Js.t {..} = "" [@@bs.send];

let render (element: ReactRe.reactElement) => {
  /* Create the renderer */
  let renderer = createRenderer ();

  /* Shallow render the component */
  render renderer element;

  /* Return the rendered output for a snapshot */
  getRenderOutput renderer;
};
