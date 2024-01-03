<h1 align="center">CSS 👗</h1>

### CSS code is made of a lot of what's called CSS rules

> This is a basic rule
```
h1 {
    color: blue;
    text-align: center;
    font-size: 20px;
}
```
The elements are:

* `h1` is called the selector

* The main content of the rule is kept inside the declaration block
```
   {
    color: blue;
    text-align: center;
    font-size: 20px;
}
```

* Inside the declaration block are the declarations/styles
```
font-size: 20px;
```

* Inside the declarations/styles there are two parts:

> The property
```
font-size
```

> And the value
```
20px
```

### You can declare rules in three different ways

1 - Inline
```
<h1 style="color: blue"> Header </h1>
```

2 - Internal
> Inside the head element
```
<style>
    h1 {
        color: blue;
    }
</style>
```

3 - External
> Inside the head element
```
<link href="style.css" rel="stylesheet"/>
```
> On the style.css file
```
h1 {
    color: blue;
}
```

### Styling Text

* Change the color `color: blue`

* Change the font-size `font-size: 20px`

* Change the font `font-family: sans-serif`

* Turn the text uppercase `text-transform: uppercase`

* Turn the text italic `text-style: italic`

* Change the line spacing `line-height: 1.5`

* Change text positioning `text-align: center`

### Combining Selectors

You can style multiple elements at once using multiple elements selector

```
h1, h2, h3, h4, p, li {
    font-family: sans-serif;
}
```

You can also use a descendent Selectors
> This will select all the `<p>` elements inside `<footer>` elements
```
footer p {
    
}
```
> You can also do
```
header nav a {
}
```

### Class and ID selectors
