<h1 align = "center">General web development annotations</h1>

### Html 🏗️

Stands for **H**yper **T**ext **M**arkup **L**anguage

HTML is used to store and describe the page content

#### Usually an HTML element has 3 elements

```
<p> Something </p>
 |      |       |
 |      |     Closing Tag
 |   Content
Opening Tag
```

Although some tags don't have any content or closing tag, like `<br>` or `<img>`

#### Basic File Structure

> Tell the browser that this website is written in HTML5

```
<!DOCTYPE html>
```

<br>

> Add the root HTML element
>
> > The root element has the `lang` attribute

```
<!DOCTYPE html">
<html lang="en">

</html>
```

<br>

> Add the `<head>` and `<body>` elements
>
> > `<head>` is where the page title and metadata will be
> >
> > `<body>` is where the visible page content will be

```
<!DOCTYPE html>
<html>
    <head>

    </head>

    <body>

    </body>
</html>
```

#### Basic Tags

- Headings

Headings can go to `<h1>` until `<h6>`

```
<h1> Heading 1 </h1>
<h2> Heading 2 </h2>
<h3> Heading 3 </h3>
...
<h6> Heading 6 </h6>
```

- Paragraphs

Just to store regular text

```
<p>This is some random text</p>
```

- Bold

To create some bold text we use `<strong>`

> The use of the `<b>` tag is not a good practice

```
<p>The following word is <strong>bold</strong></p>
```

- Italic

To create some bold text we use `<em>`, which stands for emphasise

> The use of the `<i>` tag is not a good practice

```
<p>The following word is <em>italic</em></p>
```

- Lists

Lists can be either ordered lists `<ol>` or unordered lists `<ul>`
The list elements need to be inside a `<li>` tag

```
<ul>
    <li>Flour</li>
    <li>Eggs</li>
    <li>Chantily</li>
</ul>
```

- Images

Images can be displayed on the website using the `<img>` tag

> `<img>` have two main attributes `src` and `alt`

```
<img src="assets/image.jpg" alt="description of the image">
```

> You can resize the image by using the `widht` or `height` attributes

- Metadata

Metadata stores the non visible information on the page

> `<meta>` tags are child elements of the `<head>` element

With metadata we can:

> Set the default encoding

```
<meta charset="UTF-8" />
```

- Anchors

Anchors are links that point to the website itself or to other websites

> Anchors have one main argument `href`

```
<a href="page2.html"> See other pages of our website </a>

<a href="https://google.com" target="_blank" rel="nofollow"> Go to google </a>

<a href="#"> This link goes nowhere </a>
```

- Page Structuring

`<header>` is used to tell the browser that that's the introductory content
or/and a set of navigational links

`<nav>` is used to define a set of navigation links

`<article>` is used to define an idependent item of content

`<footer>` contains information about the author of the section, copyright data or links to related documents

`<div>` a division without any meaning

`<aside>` a secondary element
