<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Glasaj.aspx.cs" Inherits="IT_LAB_1.Glasaj" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server" Visible="False">
    <asp:Image ID="Image1" runat="server" 
        ImageUrl="https://upload.wikimedia.org/wikipedia/mk/6/60/%D0%9B%D0%BE%D0%B3%D0%BE-%D0%A4%D0%98%D0%9D%D0%9A%D0%98.jpg" Width="415px" />
    <br />

    <asp:Label ID="professorName" runat="server" Text=""></asp:Label>

    <br />

    <asp:ListBox ID="lbSubject" runat="server" OnSelectedIndexChanged="subject_SelectedIndexChanged" AutoPostBack="True"></asp:ListBox>
    <asp:ListBox ID="lbCredit" runat="server" AutoPostBack="True"></asp:ListBox>

    <br />
    <asp:Button ID="addSubject" runat="server" Text="Гласај" OnClick="addSubject_Click" />

    <hr />

    Subject: <br />
    <asp:TextBox ID="tbSubject" runat="server"></asp:TextBox>
    <br />
    Credit:
    <br />
    <asp:TextBox ID="tbCredit" runat="server"></asp:TextBox>

    <br />
    <asp:Button ID="addNewSubject" runat="server" Text="Add Subject" OnClick="addNewSubject_Click" />
    <br />
    <asp:Button ID="removeSubject" runat="server" Text="Remove Subject" OnClick="removeSubject_Click" />
</asp:Content>
