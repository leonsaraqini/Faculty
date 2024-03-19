using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace IT_LAB_1
{


    public partial class Glasaj : System.Web.UI.Page
    {
        private void clearTextBox()
        {
            lbSubject.SelectedIndex = -1;
            lbCredit.SelectedIndex = -1;
            professorName.Text = "";
            tbSubject.Text = "";
            tbCredit.Text = "";
        }

        private void addASubject(string  subject, string professor, string credit)
        {
            lbSubject.Items.Add(new ListItem(subject, professor));
            lbCredit.Items.Add(new ListItem(credit, credit));
        }
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["Email"] == null)
            {
                Response.Redirect("Najava.aspx");
            }


            if(!IsPostBack)
            {
                String[] professors = { "Goce Trajkovski", "Damjan Mancevski", "Aleksandra Karanikova" };
                String[] subjects = { "Kalkulus", "Vizualno Programiranje", "Veb Dizajn" };
                String[] credits = { "5", "6", "6" };

                for (int i = 0; i < 3; i++)
               {
                    addASubject(subjects[i], professors[i], credits[i]);
               }   
            }
        }


        protected void subject_SelectedIndexChanged(object sender, EventArgs e)
        {
            lbCredit.SelectedIndex = lbSubject.SelectedIndex;
            professorName.Text = "Проф. д-р " + lbSubject.SelectedValue;         
        }

        protected void addNewSubject_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrWhiteSpace(tbSubject.Text) && !string.IsNullOrWhiteSpace(tbCredit.Text))
            {
                addASubject(tbSubject.Text, "John Doe", tbCredit.Text);

                clearTextBox();
            }
        }

        protected void removeSubject_Click(object sender, EventArgs e)
        {
            if (lbSubject.SelectedIndex != -1 && lbCredit.SelectedIndex != -1)
            {     
                lbSubject.Items.RemoveAt(lbSubject.SelectedIndex);
                lbCredit.Items.RemoveAt(lbCredit.SelectedIndex);

                clearTextBox();
            }
        }

        protected void addSubject_Click(object sender, EventArgs e)
        {
            if(lbSubject.SelectedItem != null)
            {
                Response.Redirect("UspeshnoGlasanje.aspx");
            }
        }
    }
}