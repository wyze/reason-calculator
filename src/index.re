include Styles;

module Provider = {
  let make = Reductive.Provider.createMake(Store.store);
};

let app = <Provider component=App.make />;

ReactDOMRe.renderToElementWithClassName(app, "root");
