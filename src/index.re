include Styles;

module Provider =
  Reductive.MakeProvider {
    type state = Store.state;
    type action = Store.action;
  };

let app = <Provider store=Store.store component=App.createElement />;

ReactDOMRe.renderToElementWithClassName app "root";
