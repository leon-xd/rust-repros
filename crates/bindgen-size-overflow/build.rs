use bindgen::Builder;
use std::env;
use std::path::PathBuf;

fn main() {
    println!("Hello build!");

    let bindings = Builder::default()
        .header("src/header.h")
//         .use_core()
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());

    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
