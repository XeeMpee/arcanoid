class RoutingElement {

    constructor(route, page) {
        this.route = route
        this.page = page
    }
}

class Routing{

    /// Contructor
    /// @param1: List<{string, QtQuickCOntrols2::Page}
    constructor(table) {
        this.table = table
    }

    /// Function returns page of given route from routing table
    /// @param1 <string> : route string
    /// @param2 <string> : parent name
    /// @param3 <array>  : constructor arguments of returned page
    page(route, parent='root', args={}) {
    // TODO: Fails when parent and args are not passed in invocation
        var object = null;
        this.table.forEach(element => {
            if(element.route == route) {
                var component =  Qt.createComponent(element.page);
                if (component.status == Component.Ready) {
                    object = component.createObject(parent, args);
                    if (object == null) {
                        console.log("Error creating object");
                    }
                    return object
                } else if (component.status == Component.Error) {
                    // Error Handling
                    console.log("Error loading component:", component.errorString());
                }
            } else {
                return null;
            }
        });
        if(object == null) {
            console.log("Route: " + route + " cant be find!");
        }
        return object;
    }
}