package com.example.myapplication

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.webkit.WebView
import android.webkit.WebViewClient
import android.widget.TextView
import java.io.BufferedInputStream
import java.net.HttpURLConnection
import java.net.URL

class MainActivity : AppCompatActivity() {

    @SuppressLint("SetJavaScriptEnabled", "SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        findViewById<WebView>(R.id.webview).webViewClient = WebViewClient()

        findViewById<TextView>(R.id.ip).text = "192.168.4.1"
        findViewById<TextView>(R.id.brightness).text = "100"

        findViewById<WebView>(R.id.webview).visibility = View.GONE
    }

    fun offClicked(view : View) {
        var url = "http://" + findViewById<TextView>(R.id.ip).text
        url += "/led?mode=0&brightness=" + findViewById<TextView>(R.id.brightness).text
        url += "&red=" + findViewById<TextView>(R.id.red).text
        url += "&green=" + findViewById<TextView>(R.id.green).text
        url += "&blue=" + findViewById<TextView>(R.id.blue).text

        findViewById<WebView>(R.id.webview).apply {
            loadUrl(url)
        }
    }

    fun bgClicked(view : View)  {
        var url = "http://" + findViewById<TextView>(R.id.ip).text
        url += "/led?mode=1&brightness=" + findViewById<TextView>(R.id.brightness).text
        url += "&red=" + findViewById<TextView>(R.id.red).text
        url += "&green=" + findViewById<TextView>(R.id.green).text
        url += "&blue=" + findViewById<TextView>(R.id.blue).text

        findViewById<WebView>(R.id.webview).apply {
            loadUrl(url)
        }
    }

    fun rainbowClicked(view : View)  {
        var url = "http://" + findViewById<TextView>(R.id.ip).text
        url += "/led?mode=2&brightness=" + findViewById<TextView>(R.id.brightness).text
        url += "&red=" + findViewById<TextView>(R.id.red).text
        url += "&green=" + findViewById<TextView>(R.id.green).text
        url += "&blue=" + findViewById<TextView>(R.id.blue).text

        findViewById<WebView>(R.id.webview).apply {
            loadUrl(url)
        }
    }

    fun maxbClicked(view : View)  {
        var url = "http://" + findViewById<TextView>(R.id.ip).text
        url += "/led?mode=3&brightness=" + findViewById<TextView>(R.id.brightness).text
        url += "&red=" + findViewById<TextView>(R.id.red).text
        url += "&green=" + findViewById<TextView>(R.id.green).text
        url += "&blue=" + findViewById<TextView>(R.id.blue).text

        findViewById<WebView>(R.id.webview).apply {
            loadUrl(url)
        }
    }

    fun maxnClicked(view : View)  {
        var url = "http://" + findViewById<TextView>(R.id.ip).text
        url += "/led?mode=4&brightness=" + findViewById<TextView>(R.id.brightness).text
        url += "&red=" + findViewById<TextView>(R.id.red).text
        url += "&green=" + findViewById<TextView>(R.id.green).text
        url += "&blue=" + findViewById<TextView>(R.id.blue).text

        findViewById<WebView>(R.id.webview).apply {
            loadUrl(url)
        }
    }

    fun fClicked(view : View) {
        var url = "http://" + findViewById<TextView>(R.id.ip).text
        url += "/led?mode=5&brightness=" + findViewById<TextView>(R.id.brightness).text
        url += "&red=" + findViewById<TextView>(R.id.red).text
        url += "&green=" + findViewById<TextView>(R.id.green).text
        url += "&blue=" + findViewById<TextView>(R.id.blue).text

        findViewById<WebView>(R.id.webview).apply {
            loadUrl(url)
        }
    }
}

